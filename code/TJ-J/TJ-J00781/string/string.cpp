#include<bits/stdc++.h>
using namespace std;
char ana[1000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,max=0,maxc=0;
	cin>>n;
	for(int i=0;i<n;i++){
		int cnt;
		cin>>cnt;
		char a;
		cin>>a;
		for(int i=0;i<cnt;i++){
			ana[max]=a;
			max++;
		} 
	}for(int i=0;i<=(max-1)/2;i++){
		if(ana[i]!=ana[max-1-i]){
			maxc+=1;
		}
	}cout<<maxc;
	return 0;
}
