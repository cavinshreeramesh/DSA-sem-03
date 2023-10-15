#include<bits/stdc++.h>
using namespace std;
char tree[100];
int root (char key){
  if (tree[0] != '\0')
    cout << "Tree already had root";
  else
    tree[0] = key;
  return 0;
}

int set_left (char key, int parent){
  if (tree[parent] == '\0')
    cout << "\nCan't set child at "
      << (parent * 2) + 1 << " , no parent found";
  else
    tree[(parent * 2) + 1] = key;
  return 0;
}

int set_right (char key, int parent){
  if (tree[parent] == '\0')
    cout << "\nCan't set child at "
      << (parent * 2) + 2 << " , no parent found";
  else
    tree[(parent * 2) + 2] = key;
  return 0;
}

int display (){
  cout << "\n";
  for (int i = 0; i < 100; i++)
    {
      if (tree[i] != '\0')
	cout << tree[i];
      else
	cout << "-";
    }
  return 0;
}

int main (){
  int t = 1, choice, val2;
  char val1;
  cout << "Menu" << endl;
  cout << "  1. set root\n  2. set left\n  3. set right\n  4. display" <<
    endl;
  while (t)
    {
      cout << "\nEnter choice: ";
      cin >> choice;
      switch (choice)
	{
	case 1:
	  cout << "Enter root: ";
	  cin >> val1;
	  root(val1);
	  break;
	case 2:
	  cout << "Enter data to insert: ";
	  cin >> val1;
	  cout << "Enter position of parent: ";
	  cin >> val2;
	  set_left (val1, val2);
	  break;
	case 3:
	  cout << "Enter data to insert: ";
	  cin >> val1;
	  cout << "Enter position of parent: ";
	  cin >> val2;
	  set_right (val1, val2);
	  break;
	case 4:
	  display ();
	  break;
	default:
	  t--;
	}
    }
  return 0;
}


