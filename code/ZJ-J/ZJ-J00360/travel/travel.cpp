#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,aa,bb,c,cc;
char s,ss;
signed main(){
	//freopen feropen
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a;
	scanf("%2d",&b);
	cin>>s>>aa;
	scanf("%2d",&bb);
	cin>>ss;
	
	if(ss=='F')ss--;
	if(s=='F')s--;
	if(s>='D'){
		c=1;
	}
	if(ss>='D'){
		cc=1;
	}
	//cout<<s<<" "<<ss<<endl;
	if(a==aa){
		cout<<1;
		if(b==bb){
			cout<<1;
			if(c==cc){
				cout<<1;
				if(abs(s-ss)==1){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}

