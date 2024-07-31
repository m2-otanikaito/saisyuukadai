#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// キャラクターを表すクラス
class character {
public:
    string name;  // キャラクターの名前
    int koukanndo;  // キャラクターの好感度

    character(string n, int k) : name(n), koukanndo(k) {}

    // 好感度の表示
    void hyoujikoukanndo() {
        cout << name << "の好感度: " << koukanndo << endl;
    }

    // 選択肢を表示してユーザーの選択を取得する関数
    int getchoice(const vector<string>& choices) {
        int choice;
        vector<string>::const_iterator it = choices.begin();
        for (int i = 1; it != choices.end(); ++i, ++it) {
            cout << i << ". " << *it << endl;
        }
        cin >> choice;
        // 無効な選択肢の処理
        while (cin.fail() || choice < 1 || choice > choices.size()) {
            cin.clear();  // エラー状態をクリア
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 入力バッファをクリア
            cout << "無効な選択です。再度入力してください。" << endl;
            cin >> choice;
        }
        return choice;
    }

    // かえでのストーリーを進める関数
    void kaedestory() {
        vector<string> kaedechoices1 = { "一緒に勉強しない?", "この間おすすめしてもらった本読んだよ！面白かった！" };
        int kaedeselect1 = getchoice(kaedechoices1);

        if (kaedeselect1 == 1) {
            cout << "かえで：いいよ！図書館いこー！\n";
            koukanndo += 20;

            vector<string> kaedechoices2 = { "勉強疲れたーー少し休憩しよ！", "そこ難しいよね！良かったら教えるよ！" };
            int kaedeselect2 = getchoice(kaedechoices2);

            if (kaedeselect2 == 1) {
                cout << "かえで：いいね！疲れたね――\n";
                koukanndo += 20;

                vector<string> kaedechoices3 = { "うんうん！はい！ジュース買ってきたよ！", "だね！少しお昼寝――" };
                int kaedeselect3 = getchoice(kaedechoices3);

                if (kaedeselect3 == 1) {
                    cout << "かえで：ありがとうー！気が利くね！\n";
                    koukanndo += 40;
                    kokuhaku();
                }
                else {
                    cout << "～1時間後～\n" << "かえで：おはよ！いつまで寝てるの！\n";
                    koukanndo += 10;
                    kokuhaku();
                }
            }
            else {
                cout << "かえで：ほんと！ありがとうー！助かるよ―――\n" << "～少しして～　　かえで：疲れたね！一緒に帰ろ！\n";
                koukanndo += 30;

                vector<string> kaedechoices3 = { "もちろん！この後新しくできたクレープ屋さん行こうよ！", "いいね！家まで送るよ！" };
                int kaedeselect3 = getchoice(kaedechoices3);

                if (kaedeselect3 == 1) {
                    cout << "かえで：行きたい！\n" << "～クレープを食べて～　かえで：美味しかったね！また一緒にいこ！\n";
                    koukanndo += 45;
                    kokuhaku();
                }
                else {
                    cout << "わかった！\n" << "～家について～　かえで：今日は送ってくれてありがとう！\n";
                    koukanndo += 40;
                    kokuhaku();
                }
            }
        }
        else {
            cout << "かえで：ほんと！いまその本の映画やってるから一緒に行こう！\n";
            koukanndo += 20;

            vector<string> kaedechoices2 = { "カフェでゆっくりしよう！", "カラオケ行こう！" };
            int kaedeselect2 = getchoice(kaedechoices2);

            if (kaedeselect2 == 1) {
                cout << "かえで：それいいね！\n";
                koukanndo += 30;

                vector<string> kaedechoices3 = { "さっき見た映画の話", "課題の話" };
                int kaedeselect3 = getchoice(kaedechoices3);

                if (kaedeselect3 == 1) {
                    cout << "それにしても楽しかったね！また一緒に遊ぼ！\n";
                    koukanndo += 40;
                    kokuhaku();
                }
                else {
                    cout << "課題のこと思い出しちゃったよ――忘れてたのに！\n";
                    koukanndo += 15;
                    kokuhaku();
                }
            }
            else {
                cout << "元気だね！いいよーー\n";
                koukanndo += 20;

                vector<string> kaedechoices3 = { "J-POP", "ラップ" };
                int kaedeselect3 = getchoice(kaedechoices3);

                if (kaedeselect3 == 1) {
                    cout << "私もその歌よく聞く！いいよね！しかも" << name << "って歌上手いんだね！\n";
                    koukanndo += 40;
                    kokuhaku();
                }
                else {
                    cout << "私そういう系あんまり聞かないからわからないけど，なんかすごい！\n";
                    koukanndo += 10;
                    kokuhaku();
                }
            }
        }
    }

    // ソフィアのストーリーを進める関数
    void sophiastory() {
        vector<string> sophiachoices1 = { "一緒にお昼ご飯食べよ！", "一緒に購買いこう！" };
        int sophiaselect1 = getchoice(sophiachoices1);

        if (sophiaselect1 == 1) {
            cout << "ソフィア：いいよ！教室で食べよー！\n";
            koukanndo += 20;

            vector<string> sophiachoices2 = { "お弁当美味しいねー！今日の自主練行く？", "午前疲れたね――！放課後遊びに行かない？" };
            int sophiaselect2 = getchoice(sophiachoices2);

            if (sophiaselect2 == 1) {
                cout << "だね！行こうかと思ってる！終わったら一緒に帰ろー！\n";
                koukanndo += 30;

                vector<string> sophiachoices3 = { "疲れたね！少し寄り道しよ！", "お疲れさま！家まで送るよ！" };
                int sophiaselect3 = getchoice(sophiachoices3);

                if (sophiaselect3 == 1) {
                    cout << "～海辺にて～\n" << "やっぱ海辺は気持ちいね！またこよーー！\n";
                    koukanndo += 50;
                    kokuhaku();
                }
                else {
                    cout << "～ソフィアの家について～\n" << "送ってくれてありがとう！こんど遊びにも行こうね！\n";
                    koukanndo += 35;
                    kokuhaku();
                }
            }
            else {
                cout << "ソフィア：いいよ！自主練あるけど行っちゃうか！どこ行くー？\n";
                koukanndo += 20;

                vector<string> sophiachoices3 = { "ボウリング行こう！", "ゲーセン行こうよ！" };
                int sophiaselect3 = getchoice(sophiachoices3);

                if (sophiaselect3 == 1) {
                    cout << "～ボウリング場にて～\n" << "ボウリング上手いんだね！やるじゃん！\n";
                    koukanndo += 20;
                    kokuhaku();
                }
                else {
                    cout << "～ゲーセンにて～\n" << "これ欲しかったんだ～！とってくれてありがとう！\n";
                    koukanndo += 20;
                    kokuhaku();
                }
            }
        }
        else {
            cout << "いいね！ちょうど行こうと思ってた！\n";
            koukanndo += 20;

            vector<string> sophiachoices2 = { "ソフィア！数量限定のメロンパンあるよ！", "ちょっと待ってて！（急いで数量限定メロンパンを買いに行く）" };
            int sophiaselect2 = getchoice(sophiachoices2);

            if (sophiaselect2 == 1) {
                cout << "ほんとだ！あ！でもとられちゃったーー　とりあえず屋上行こ！\n";
                koukanndo += 10;

                vector<string> sophiachoices3 = { "あのメロンパンほんと人気だよね！次こそゲットしよ！", "屋上結構暑いねー！" };
                int sophiaselect3 = getchoice(sophiachoices3);

                if (sophiaselect3 == 1) {
                    cout << "だね！屋上気持ちいいー！\n";
                    koukanndo += 20;
                    kokuhaku();
                }
                else {
                    cout << "そうー？風が気持ちよくて割と好き！\n";
                    koukanndo += 10;
                    kokuhaku();
                }
            }
            else {
                cout << "はい！これメロンパン！\n" << "ありがとうーー！ほんとに嬉しい！！どこで食べる―？\n";
                koukanndo += 30;

                vector<string> sophiachoices3 = { "屋上いこ！", "空き教室にいこう！" };
                int sophiaselect3 = getchoice(sophiachoices3);

                if (sophiaselect3 == 1) {
                    cout << "～屋上にて～\n" << "メロンパンめっちゃおいしい！屋上風吹いてて気持ちいいね！\n";
                    koukanndo += 30;
                    kokuhaku();
                }
                else {
                    cout << "～空き教室にて～\n" << "メロンパンうまっ！ありがとね！\n";
                    koukanndo += 20;
                    kokuhaku();
                }
            }
        }
    }

    void kokuhaku() {
        cout << "告白しますか? (1: はい, 2: いいえ): ";
        int kokuhakuselect;
        cin >> kokuhakuselect;

        while (cin.fail() || (kokuhakuselect != 1 && kokuhakuselect != 2)) {
            cin.clear();  // エラー状態をクリア
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 入力バッファをクリア
            cout << "無効な選択です。再度入力してください。" << endl;
            cout << "告白しますか? (1: はい, 2: いいえ): ";
            cin >> kokuhakuselect;
        }

        if (kokuhakuselect == 1) {
            if (koukanndo >= 80) {
                cout << "好きです，付き合ってください！" << endl;
                cout << "嬉しい、、私も好きだよ！これからもよろしくね！　～happy end～" << endl;
            }
            else {
                cout << "好きです，付き合ってください！" << endl;
                cout << "ごめんなさい. 気持ちは嬉しいけど今は友達のままで居たいな．　～bad end～\n" << endl;
            }
        }
        else {
            cout << "どうしても告白する勇気が出ない.　～bad end～\n" << endl;
        }

        cout << "ストーリーを踏破しました.\n" << endl;
        cout << "最終的な好感度は" << koukanndo << "でした！\n" << endl;
        cout << "プレイありがとうございました！\n" << endl;
    }
};

// プレイヤー名の入力
string nyuuryokuname() {
    string name;
    cout << "プレイヤー名を入力してください: ";
    getline(cin, name);
    while (name.empty()) {
        cout << "名前を入力してください（空白は無効です）: ";
        getline(cin, name);
    }
    cout << "プレイヤー名: " << name << endl;
    return name;
}

// メイン関数
int main() {
    string playername = nyuuryokuname();

    cout << "話しかけるキャラクターを選んで番号をキーボードで入力してね！（選択によってストーリーが変わるよ！）\n";
    cout << "1.かえで\n" << "2.ソフィア\n";
    int characterselect;
    cin >> characterselect;
    while (cin.fail() || (characterselect != 1 && characterselect != 2)) {
        cin.clear();  // エラー状態をクリア
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 入力バッファをクリア
        cout << "無効な選択です。再度入力してください。" << endl;
        cout << "話しかけるキャラクターを選んで番号をキーボードで入力してね！（選択によってストーリーが変わるよ！）\n";
        cout << "1.かえで\n" << "2.ソフィア\n";
        cin >> characterselect;
    }

    if (characterselect == 1) {
        character kaede("かえで", 0);
        kaede.kaedestory();
    }
    else {
        character sophia("ソフィア", 0);
        sophia.sophiastory();
    }

    return 0;
}