#include <string>
#include <fstream>
#include <climits>
#include <iostream>

using namespace std;

struct tnode {
	int val;
	tnode* l;
	tnode* r;

	tnode(int x = 0) :val(x), l(nullptr), r(nullptr) {}
};

tnode* build(int a[], int le, int ri) {
	int max = INT_MIN, idx = -1;
	for (int i = le; i < ri; i++) {
		if (a[i] > max) {
			max = a[i];
			idx = i;
		}
	}
	if (idx != -1) {
		tnode* t = new tnode(max);
		t->l = build(a, le, idx);
		t->r = build(a, idx + 1, ri);
		return t;
	}
	else return nullptr;
}

string ntos(tnode* root) {
	if (!root)return "";
	if (root->l && root->r)return to_string(root->val) + "(" + ntos(root->l) + ',' + ntos(root->r) + ')';
	else if (root->l && !root->r)return to_string(root->val) + '(' + ntos(root->l) + ')';
	else if (!root->l && root->r)return to_string(root->val) + "(," + ntos(root->r) + ')';
	else return to_string(root->val);
}

void t(tnode* r) {
	if (!r)return;
	cout << r->val << endl;
	t(r->l);
	t(r->r);
	return;
}

const int N = 101010;

int a[N],cnt = 0;

int main()
{
	ifstream file("in.txt", ios::in);
	while (file >> a[cnt++]);

	tnode* root = build(a, 0, cnt-1);

	cout << ntos(root);

	return 0;
}