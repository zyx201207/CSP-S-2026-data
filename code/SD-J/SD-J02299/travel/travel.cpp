#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define x1 x_1
#define x2 x_2
#define y1 y_1
#define y2 y_2
using namespace std;

long long read(){
	char ch=getchar();
	long long res=0;
	int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	return res*f;
}
string a,b,c,d;
int main(){
	//一定一定要记得初始化！！！！！
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c) cout<<1;
    else cout<<0;
    if(a==c&&b[0]==d[0]&&b[1]==d[1]) cout<<1;
    else cout<<0;
    if(a==c&&b[0]==d[0]&&b[1]==d[1]){
    	int f,f_;
    	if(b[2]=='A'||b[2]=='B'||b[2]=='C') f=1;
    	else f=0;
    	if(d[2]=='A'||d[2]=='B'||d[2]=='C') f_=1;
    	else f_=0;
    	if(f==f_) cout<<1;
    	else cout<<0;
	}
	else cout<<0;
	if(a==c&&b[0]==d[0]&&b[1]==d[1]){
		int k,k_;
		k=b[2]-'A';
		k_=d[2]-'A';
		if((k==0&&k_==1)||(k==1&&k_==0)||(k==1&&k_==2)||(k==2&&k_==1)||(k==4&&k_==6)||(k==6&&k_==4)) cout<<1;
		else cout<<0;
	}
	else cout<<0;
	return 0;
}

