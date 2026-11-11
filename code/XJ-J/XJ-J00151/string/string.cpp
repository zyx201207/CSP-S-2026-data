#include<bits/stdc++.h>
using namespace std;
int n,maxn=0,all=0;
int list1[200005];
int ans=1000000005;
int chan(int all1){
	int ans1=0;
	for(int i=1;i<=all1/2;i++){
		if(list1[i]!=list1[all1-i+1]) ans1+=1;
	}
	return ans1;
}
int main(){
	freopen("string1.in","r",stdin);
	freopen("string1.ans","w",stdout);
	freopen("string2.in","r",stdin);
	freopen("string2.ans","w",stdout);
	freopen("string3.in","r",stdin);
	freopen("string3.ans","w",stdout);
	freopen("string4.in","r",stdin);
	freopen("string4.ans","w",stdout);
	freopen("string5.in","r",stdin);
	freopen("string5.ans","w",stdout);
	freopen("string6.in","r",stdin);
	freopen("string6.ans","w",stdout);
	cin>>n;
	int now=1;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		char c;
		cin>>c;
		all+=a;
		for(int j=all-a+1;j<=all;j++){
			list1[j]=c-'a'+1;
			maxn=max(maxn,list1[j]);
		}
		now+=a;
	}
	cout<<chan(all);
	return 0; 
} 
