#include<bits/stdc++.h>
#define ll long long
#define ull long long
#define ls(x) x<<1
#define rs(x) x<<1|1
#define N 100000
#define M 100000
#define inf 1000000000
#define pii pair<int,int>
#define endl "\n"
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	int a1=0,a2=0;
	for(int i=0;i<s1.size()-1;i++){
		a1=(a1*10)+s1[i]-'0';
	}
	for(int i=0;i<s2.size()-1;i++){
		a2=(a2*10)+s2[i]-'0';
	}
	if (a1==a2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	int f1=('A'<=s1[s1.size()-1]&&s1[s1.size()-1]<='C');
	int f2=('D'<=s1[s1.size()-1]&&s1[s1.size()-1]<='F');
	int f3=('A'<=s2[s2.size()-1]&&s2[s2.size()-1]<='C');
	int f4=('D'<=s2[s2.size()-1]&&s2[s2.size()-1]<='F');
	int f5=(a1==a2&&(f1==f3||f2==f4));
	if (f5){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(f5&&abs(s2[s2.size()-1]-s1[s1.size()-1])==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
