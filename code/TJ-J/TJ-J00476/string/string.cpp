#include<bits/stdc++.h>
using namespace std;
struct Node{
	int num;
	char c;
};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	Node node[n];
	for (int i=0;i<n;i++){
		cin >> node[i].num >> node[i].c;
	}
//	for (int i=0,j=n-1;i<=j;i++,j--){}
	int i=0;
	int j=n-1;
	unsigned long long res=0;
	while(i<j){
		if (node[i].c==node[j].c){
			if (node[i].num>node[j].num){
				int l=node[i].num-node[j].num;
				node[i].num=l;
				j--;
			}
			else if(node[i].num<node[j].num){
				int l=node[j].num-node[i].num;
				node[j].num=l;
				i++;
			}
			else{
				i++;
				j--;
			}
		}
		else if(node[i].c!=node[j].c){
			if (node[i].num>node[j].num){
				int l=node[i].num-node[j].num;
				node[i].num=l;
				res+=node[j].num;
				j--;
			}
			else if(node[i].num<node[j].num){
				int l=node[j].num-node[i].num;
				node[j].num=l;
				res+=node[i].num;
				i++;

			}
			else{
				res+=node[i].num;
				i++;
				j--;
			}
		}
	}
	cout << res;
}
