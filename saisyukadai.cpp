#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// �L�����N�^�[��\���N���X
class character {
public:
    string name;  // �L�����N�^�[�̖��O
    int koukanndo;  // �L�����N�^�[�̍D���x

    character(string n, int k) : name(n), koukanndo(k) {}

    // �D���x�̕\��
    void hyoujikoukanndo() {
        cout << name << "�̍D���x: " << koukanndo << endl;
    }

    // �I������\�����ă��[�U�[�̑I�����擾����֐�
    int getchoice(const vector<string>& choices) {
        int choice;
        vector<string>::const_iterator it = choices.begin();
        for (int i = 1; it != choices.end(); ++i, ++it) {
            cout << i << ". " << *it << endl;
        }
        cin >> choice;
        // �����ȑI�����̏���
        while (cin.fail() || choice < 1 || choice > choices.size()) {
            cin.clear();  // �G���[��Ԃ��N���A
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ���̓o�b�t�@���N���A
            cout << "�����ȑI���ł��B�ēx���͂��Ă��������B" << endl;
            cin >> choice;
        }
        return choice;
    }

    // �����ł̃X�g�[���[��i�߂�֐�
    void kaedestory() {
        vector<string> kaedechoices1 = { "�ꏏ�ɕ׋����Ȃ�?", "���̊Ԃ������߂��Ă�������{�ǂ񂾂�I�ʔ��������I" };
        int kaedeselect1 = getchoice(kaedechoices1);

        if (kaedeselect1 == 1) {
            cout << "�����ŁF������I�}���ق����[�I\n";
            koukanndo += 20;

            vector<string> kaedechoices2 = { "�׋���ꂽ�[�[�����x�e����I", "���������ˁI�ǂ������狳�����I" };
            int kaedeselect2 = getchoice(kaedechoices2);

            if (kaedeselect2 == 1) {
                cout << "�����ŁF�����ˁI��ꂽ�ˁ\�\\n";
                koukanndo += 20;

                vector<string> kaedechoices3 = { "���񂤂�I�͂��I�W���[�X�����Ă�����I", "���ˁI���������Q�\�\" };
                int kaedeselect3 = getchoice(kaedechoices3);

                if (kaedeselect3 == 1) {
                    cout << "�����ŁF���肪�Ƃ��[�I�C�������ˁI\n";
                    koukanndo += 40;
                    kokuhaku();
                }
                else {
                    cout << "�`1���Ԍ�`\n" << "�����ŁF���͂�I���܂ŐQ�Ă�́I\n";
                    koukanndo += 10;
                    kokuhaku();
                }
            }
            else {
                cout << "�����ŁF�ق�ƁI���肪�Ƃ��[�I�������\�\�\\n" << "�`�������ā`�@�@�����ŁF��ꂽ�ˁI�ꏏ�ɋA��I\n";
                koukanndo += 30;

                vector<string> kaedechoices3 = { "�������I���̌�V�����ł����N���[�v������s������I", "�����ˁI�Ƃ܂ő����I" };
                int kaedeselect3 = getchoice(kaedechoices3);

                if (kaedeselect3 == 1) {
                    cout << "�����ŁF�s�������I\n" << "�`�N���[�v��H�ׂā`�@�����ŁF�������������ˁI�܂��ꏏ�ɂ����I\n";
                    koukanndo += 45;
                    kokuhaku();
                }
                else {
                    cout << "�킩�����I\n" << "�`�Ƃɂ��ā`�@�����ŁF�����͑����Ă���Ă��肪�Ƃ��I\n";
                    koukanndo += 40;
                    kokuhaku();
                }
            }
        }
        else {
            cout << "�����ŁF�ق�ƁI���܂��̖{�̉f�����Ă邩��ꏏ�ɍs�����I\n";
            koukanndo += 20;

            vector<string> kaedechoices2 = { "�J�t�F�ł�����肵�悤�I", "�J���I�P�s�����I" };
            int kaedeselect2 = getchoice(kaedechoices2);

            if (kaedeselect2 == 1) {
                cout << "�����ŁF���ꂢ���ˁI\n";
                koukanndo += 30;

                vector<string> kaedechoices3 = { "�����������f��̘b", "�ۑ�̘b" };
                int kaedeselect3 = getchoice(kaedechoices3);

                if (kaedeselect3 == 1) {
                    cout << "����ɂ��Ă��y���������ˁI�܂��ꏏ�ɗV�ځI\n";
                    koukanndo += 40;
                    kokuhaku();
                }
                else {
                    cout << "�ۑ�̂��Ǝv���o�����������\�\�Y��Ă��̂ɁI\n";
                    koukanndo += 15;
                    kokuhaku();
                }
            }
            else {
                cout << "���C���ˁI������[�[\n";
                koukanndo += 20;

                vector<string> kaedechoices3 = { "J-POP", "���b�v" };
                int kaedeselect3 = getchoice(kaedechoices3);

                if (kaedeselect3 == 1) {
                    cout << "�������̉̂悭�����I������ˁI������" << name << "���ĉ̏�肢�񂾂ˁI\n";
                    koukanndo += 40;
                    kokuhaku();
                }
                else {
                    cout << "�����������n����܂蕷���Ȃ�����킩��Ȃ����ǁC�Ȃ񂩂������I\n";
                    koukanndo += 10;
                    kokuhaku();
                }
            }
        }
    }

    // �\�t�B�A�̃X�g�[���[��i�߂�֐�
    void sophiastory() {
        vector<string> sophiachoices1 = { "�ꏏ�ɂ������ѐH�ׂ�I", "�ꏏ�ɍw���������I" };
        int sophiaselect1 = getchoice(sophiachoices1);

        if (sophiaselect1 == 1) {
            cout << "�\�t�B�A�F������I�����ŐH�ׂ�[�I\n";
            koukanndo += 20;

            vector<string> sophiachoices2 = { "���ٓ����������ˁ[�I�����̎�����s���H", "�ߑO��ꂽ�ˁ\�\�I���ی�V�тɍs���Ȃ��H" };
            int sophiaselect2 = getchoice(sophiachoices2);

            if (sophiaselect2 == 1) {
                cout << "���ˁI�s�������Ǝv���Ă�I�I�������ꏏ�ɋA��[�I\n";
                koukanndo += 30;

                vector<string> sophiachoices3 = { "��ꂽ�ˁI������蓹����I", "����ꂳ�܁I�Ƃ܂ő����I" };
                int sophiaselect3 = getchoice(sophiachoices3);

                if (sophiaselect3 == 1) {
                    cout << "�`�C�ӂɂā`\n" << "����ϊC�ӂ͋C�������ˁI�܂�����[�[�I\n";
                    koukanndo += 50;
                    kokuhaku();
                }
                else {
                    cout << "�`�\�t�B�A�̉Ƃɂ��ā`\n" << "�����Ă���Ă��肪�Ƃ��I����ǗV�тɂ��s�����ˁI\n";
                    koukanndo += 35;
                    kokuhaku();
                }
            }
            else {
                cout << "�\�t�B�A�F������I��������邯�Ǎs�����Ⴄ���I�ǂ��s���[�H\n";
                koukanndo += 20;

                vector<string> sophiachoices3 = { "�{�E�����O�s�����I", "�Q�[�Z���s������I" };
                int sophiaselect3 = getchoice(sophiachoices3);

                if (sophiaselect3 == 1) {
                    cout << "�`�{�E�����O��ɂā`\n" << "�{�E�����O��肢�񂾂ˁI��邶���I\n";
                    koukanndo += 20;
                    kokuhaku();
                }
                else {
                    cout << "�`�Q�[�Z���ɂā`\n" << "����~���������񂾁`�I�Ƃ��Ă���Ă��肪�Ƃ��I\n";
                    koukanndo += 20;
                    kokuhaku();
                }
            }
        }
        else {
            cout << "�����ˁI���傤�Ǎs�����Ǝv���Ă��I\n";
            koukanndo += 20;

            vector<string> sophiachoices2 = { "�\�t�B�A�I���ʌ���̃������p�������I", "������Ƒ҂��ĂāI�i�}���Ő��ʌ��胁�����p���𔃂��ɍs���j" };
            int sophiaselect2 = getchoice(sophiachoices2);

            if (sophiaselect2 == 1) {
                cout << "�ق�Ƃ��I���I�ł��Ƃ�ꂿ������[�[�@�Ƃ肠��������s���I\n";
                koukanndo += 10;

                vector<string> sophiachoices3 = { "���̃������p���ق�Ɛl�C����ˁI�������Q�b�g����I", "���㌋�\�����ˁ[�I" };
                int sophiaselect3 = getchoice(sophiachoices3);

                if (sophiaselect3 == 1) {
                    cout << "���ˁI����C���������[�I\n";
                    koukanndo += 20;
                    kokuhaku();
                }
                else {
                    cout << "�����[�H�����C�����悭�Ċ��ƍD���I\n";
                    koukanndo += 10;
                    kokuhaku();
                }
            }
            else {
                cout << "�͂��I���ꃁ�����p���I\n" << "���肪�Ƃ��[�[�I�ق�ƂɊ������I�I�ǂ��ŐH�ׂ�\�H\n";
                koukanndo += 30;

                vector<string> sophiachoices3 = { "���ア���I", "�󂫋����ɂ������I" };
                int sophiaselect3 = getchoice(sophiachoices3);

                if (sophiaselect3 == 1) {
                    cout << "�`����ɂā`\n" << "�������p���߂����Ⴈ�������I���㕗�����ĂċC���������ˁI\n";
                    koukanndo += 30;
                    kokuhaku();
                }
                else {
                    cout << "�`�󂫋����ɂā`\n" << "�������p�����܂��I���肪�ƂˁI\n";
                    koukanndo += 20;
                    kokuhaku();
                }
            }
        }
    }

    void kokuhaku() {
        cout << "�������܂���? (1: �͂�, 2: ������): ";
        int kokuhakuselect;
        cin >> kokuhakuselect;

        while (cin.fail() || (kokuhakuselect != 1 && kokuhakuselect != 2)) {
            cin.clear();  // �G���[��Ԃ��N���A
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ���̓o�b�t�@���N���A
            cout << "�����ȑI���ł��B�ēx���͂��Ă��������B" << endl;
            cout << "�������܂���? (1: �͂�, 2: ������): ";
            cin >> kokuhakuselect;
        }

        if (kokuhakuselect == 1) {
            if (koukanndo >= 80) {
                cout << "�D���ł��C�t�������Ă��������I" << endl;
                cout << "�������A�A�����D������I���ꂩ�����낵���ˁI�@�`happy end�`" << endl;
            }
            else {
                cout << "�D���ł��C�t�������Ă��������I" << endl;
                cout << "���߂�Ȃ���. �C�����͊��������Ǎ��͗F�B�̂܂܂ŋ������ȁD�@�`bad end�`\n" << endl;
            }
        }
        else {
            cout << "�ǂ����Ă���������E�C���o�Ȃ�.�@�`bad end�`\n" << endl;
        }

        cout << "�X�g�[���[�𓥔j���܂���.\n" << endl;
        cout << "�ŏI�I�ȍD���x��" << koukanndo << "�ł����I\n" << endl;
        cout << "�v���C���肪�Ƃ��������܂����I\n" << endl;
    }
};

// �v���C���[���̓���
string nyuuryokuname() {
    string name;
    cout << "�v���C���[������͂��Ă�������: ";
    getline(cin, name);
    while (name.empty()) {
        cout << "���O����͂��Ă��������i�󔒂͖����ł��j: ";
        getline(cin, name);
    }
    cout << "�v���C���[��: " << name << endl;
    return name;
}

// ���C���֐�
int main() {
    string playername = nyuuryokuname();

    cout << "�b��������L�����N�^�[��I��Ŕԍ����L�[�{�[�h�œ��͂��ĂˁI�i�I���ɂ���ăX�g�[���[���ς���I�j\n";
    cout << "1.������\n" << "2.�\�t�B�A\n";
    int characterselect;
    cin >> characterselect;
    while (cin.fail() || (characterselect != 1 && characterselect != 2)) {
        cin.clear();  // �G���[��Ԃ��N���A
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ���̓o�b�t�@���N���A
        cout << "�����ȑI���ł��B�ēx���͂��Ă��������B" << endl;
        cout << "�b��������L�����N�^�[��I��Ŕԍ����L�[�{�[�h�œ��͂��ĂˁI�i�I���ɂ���ăX�g�[���[���ς���I�j\n";
        cout << "1.������\n" << "2.�\�t�B�A\n";
        cin >> characterselect;
    }

    if (characterselect == 1) {
        character kaede("������", 0);
        kaede.kaedestory();
    }
    else {
        character sophia("�\�t�B�A", 0);
        sophia.sophiastory();
    }

    return 0;
}