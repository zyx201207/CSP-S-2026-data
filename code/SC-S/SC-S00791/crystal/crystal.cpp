#include<bits/stdc++.h>
using namespace std;
int same(vector<int> list){
	int n=list.size();
	int same_num[n+1];
	for(int s=0;s<n+1;s++){
		same_num[s]=0;
	}
	int num=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(list.at(i)==list.at(j)){
				same_num[i]++;
			}
		}
	}
	for(int b=0;b<n+1;b++){
		if(same_num[b]>num){
			num=same_num[b];
		}
	}
	return num+1;
}
int func(vector<int> list, int m, int& max){
	if(m<=0){
		int a=same(list);
		if(a>max){
			max=a;
		}
		return 0;
	}
	for(int i=0;i<list.size();i++){
		list[i]++;
		func(list, m-1, max);
		list[i]--;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.ans","w",stdout);
	int max=0;
	int n,m;
	cin>>n>>m;
	vector<int> list(n);
	for(int i=0;i<n;i++){
		cin>>list[i];
	}
	func(list, m, max);
	cout<<max;
	return 0;
}