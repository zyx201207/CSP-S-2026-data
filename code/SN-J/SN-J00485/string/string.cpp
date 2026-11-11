#include<bits/stdc++.h>

using namespace std;
//struct node{
//	int st,ed;
//	char c;
//}st[200000+6];
int main(){
//	ios::sync_with_stdio(false);
	freopen("srting.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	string st="";
	cin>>a;
//	ll sum=0;
	for(int i=1;i<=a;i++){
		int in;
		char in2;
		cin>>in>>in2;
		for(int j=1;j<=in;j++){
			st+=in2;
		}
	}
	int len=st.size();
	long long cnt=0;
	for(int i=0;i<=len/2;i++){
		if(st[i]!=st[len-i-1])cnt++;
	}
	cout<<cnt;
//	ll mid=(sum+1)/2;
//	int is;//1ÆæÊý0Å¼Êý 
//	if(sum%2==0)is=0;
//	else is=1;
//	sum=0;
//	for(int i=1;i<=a;i++){
//		if(st[i].ed>=mid){
//			for(int j=a;j>=i+1;j--){
//				st[i+1].n=st[i].n;
//			}
//		}
//	}//cut
//	for(int i=1;i<)
}// finish!
