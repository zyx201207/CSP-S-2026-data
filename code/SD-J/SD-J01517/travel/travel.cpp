#include<bits/stdc++.h>
using namespace std;
int r1,x1,r2,x2;
char a,b;
int sec[1010];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>a>>x1>>x2>>b;
	sec['A']=1;
	sec['B']=1;
	sec['C']=1;
	sec['D']=0;
	sec['F']=0;
	if(r1==x1){
	    cout<<1;
	    if(r2==x2){
			cout<<1;
			if(sec[a]==sec[b]){
				cout<<1;
				if(sec[a]){
					if(a-b==1||a-b==-1) cout<<1;
					else cout<<0;
				}
				else cout<<1;
			}
			else{
				cout<<0<<0;
			}
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

