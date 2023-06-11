#include <iostream>
#include <stdlib.h>
using namespace std;

//узел дерева
struct NODE {
	int info; //информация в узле
	NODE* left; //левое поддерево
	NODE* right; //правое поддерево

	NODE(int newInfo, NODE* newLeft, NODE* newRight) {
		info = newInfo;
		left = newLeft;
		right = newRight;
	}

	NODE(int newInfo) {
		info = newInfo;
		left = nullptr;
		right = nullptr;
	}

	NODE() {
		info = NULL;
		left = nullptr;
		right = nullptr;
	}
};

typedef NODE* Tree; //"typedef" - type definition

// Печать при прямом обходе дерева
void Preorder_Print(Tree t) {
	if (t != NULL) {
		cout << t->info << " ";
		Preorder_Print(t->left);
		Preorder_Print(t->right);
	}
}

// Печать при симметричном обходе дерева
void Inorder_Print(Tree t)
{
	if (t != NULL)
	{
		Inorder_Print(t->left);
		cout << t->info << ' ';
		Inorder_Print(t->right);
	}
}

// Сумма значений элементов при симметричном обходе дерева
int Inorder_Sum(Tree t) {
	if (t != NULL) {
		return Inorder_Sum(t->left) + t->info + Inorder_Sum(t->right);
	}
	return 0;
}

// Сумма значений элементов при прямом обходе дерева
int Preoder_Sum(Tree t) {
	if (t != NULL) {
		return t->info + Preoder_Sum(t->left) + Preoder_Sum(t->right);
	}
	return 0;
}

// Поиск минимума в дереве 
int Preoder_Min(Tree t, int mi) {
	int minRoot, minLeft, minRight;
	if (t != NULL) {
		minRoot = min(mi, t->info);
		minLeft = Preoder_Min(t->left, minRoot);
		minRight = Preoder_Min(t->right, minLeft);
		return minRight;
	}
	return mi;
}

// Поиск минимума в бинарном дереве
int Min(Tree t) {
	while (t->left != NULL) {
		t = t->left;
	} 
	return t->info;
}

int main() {
	setlocale(LC_ALL, "rus");
	Tree tree = new NODE(11);
	tree->left = new NODE(7);
	tree->right = new NODE(9);
	tree->right->left = new NODE(13);

	Tree binaryTree = new NODE(9);
	binaryTree->left = new NODE(7);
	binaryTree->right = new NODE(11);
	binaryTree->right->right = new NODE(13);

	cout << " Дерево " << endl;
	Preorder_Print(tree);
	cout << endl;
	cout << " Бинарное дерево " << endl;
	Inorder_Print(binaryTree);
	cout << endl;
	cout << "Сумма элементов при прямом обходе дерева: " << Preoder_Sum(tree) << endl; 
	cout << "Сумма элементов при симметричном обходе дерева: " << Inorder_Sum(tree) << endl;
	cout << "Минимальный элемент NULL дерева: " << Preoder_Min(NULL, INT_MAX) << endl;
	cout << "Минимальный элемент дерева: " << Preoder_Min(tree, INT_MAX) << endl;
	cout << "Минимальный элемент бинарного дерева: " << Min(binaryTree) << endl;

	system("pause");
	return 0;
}


//Node minimum(x : Node) :
//    if x.left == null
//        return x
//        return minimum(x.left)