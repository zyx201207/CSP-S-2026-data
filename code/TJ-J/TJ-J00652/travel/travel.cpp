#include<bits/stdc++.h>
using namespace std;
void read(long long &a){
	char ch;
	int f=1;
	for(;ch=getchar();){
		if('0'<=ch&&ch<='9'){
			a=ch-'0';
			break;
		}else if(ch=='-'){
			f*=-1;
		}
	}for(;ch=getchar();){
		if('0'>ch||ch>'9'){
			a*=f;
			return ;
		}a=a*10+(ch-'0');
	}
}long long n,x;
string m,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	read(n);
	cin>>m;
	read(x);
	cin>>y;
	bool a;
	if(n==x){
		a=1;
		cout<<1;
		if(m[0]==y[0]&&m[1]==y[1]){
			cout<<1;
			if(('C'>=m[2]&&'C'>=y[2])||('D'<=m[2]&&'D'<=y[2])){
				cout<<1;
				if(m[2]+1==y[2]||m[2]-1==y[2]){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
} 
