#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int j=0,p=0,k=0,t=0,q=0,w=0;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		j=1;
	}
	else cout<<0;
	if(j==1){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			p=1;
		}
		else cout<<0;
	}
	else cout<<0;
	if(j==1&&p==1){
		if((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C')) t=1;
		if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')) k=1;
	}
	if(t==1||k==1) cout<<1;
	else cout<<0;
	
	if(j==1&&p==1){
		if(t==1){
			if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1){
				q=1;
			}
		}
		else if(k==1){
			if(s1[2]-s2[2]==2||s1[2]-s2[2]==-2){
				w=1;
			}
		}
	}
	if(w==1||q==1)cout<<1;
	else cout<<0;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
