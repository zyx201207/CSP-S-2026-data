#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=0;
string s,p;
bool cmp(int x,int y){
	return x>y;
}
//void anweiyu(){
//	int lenu=s.size(),lenv=p.size();
//	int len=min(lenu,lenv);
//	for(int i=0;i<len;i++){
//		if(s[i]==p[i]) p[i]='1';
//		else p[i]='0';
//	}
//}
//void init(string &str){
//	int len=str.size();
//	for(int i=0;i<len;i++){
//		str[i]='0';
//	}
//}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}
//	for(int i=1;i<=m;i++){
//		init(s);
//		if(i>=2){
//			p=s;
//		}
//		int t=0,x=a[i];
//		while(x>0){
//			if(x%2)
//				s[t++]='1';
//			else
//				s[t++]='0';
//			x/=2;
//		}
//		for(int j=0;j<t;j++) cout<<s[j];
//		if(i!=1){
//			anweiyu();
//		}
//	}
//	int len=p.size(),k=1;
//	for(int i=0;i<len;i++){
//		ans+=(p[i]-'0')*k;
//		k*=2;
//	}
//	cout<<ans;
	return 0;
}      
/*
4 2
3 15 12 12
*/ 
