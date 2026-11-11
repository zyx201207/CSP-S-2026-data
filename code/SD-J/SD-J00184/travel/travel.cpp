#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=10;
int a[N];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c1,c2,x,y;
	char s1,s2;
	cin>>c1>>x>>s1>>c2>>y>>s2;
	bool f1=0;
	if(c1==c2){
		a[1]=1;
	}else{
		a[1]=0;
		a[2]=0;
		a[3]=0;
		a[4]=0;
		f1=1;
	}
	if(f1==1){
		for(int i=1;i<=4;i++){
			cout<<a[i];
		}
		return 0;
	}
	bool f=0;
	if(x==y){
		a[2]=1;
	}else{
		a[2]=0;
		a[3]=0;
		a[4]=0;
		f=1;
	}
	if(f==1){
		for(int i=1;i<=4;i++){
			cout<<a[i];
		}
		return 0;
	}
	if((s1=='A'||s1=='B'||s1=='C')&&(s2=='A'||s2=='B'||s2=='C')){
		a[3]=1;
	}else if((s1=='D'||s1=='F')&&(s2=='D'||s2=='F')){
		a[3]=1;
	}else{
		a[3]=0;
	}
	if(s1=='A'&&s2=='B'){
		a[4]=1;
	}else if(s1=='B'&&s2=='C'){
		a[4]=1;
	}else if(s1=='D'&&s2=='F'){
		a[4]=1;
	}else{
		a[4]=0;
	}
	for(int i=1;i<=4;i++){
		cout<<a[i];
	}
	return 0;
}
