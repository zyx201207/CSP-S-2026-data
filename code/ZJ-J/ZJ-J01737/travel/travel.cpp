#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int sum=0;	
	cin>>a>>b>>c>>d;
	int e=b.size(),f=d.size();
	for(int i=0;i<e-1;i++){
		if(b[i]!=d[i])sum++;
	}
	if(a==c){
		cout<<1;
		if(sum==0){
			cout<<1;
			if(b[e-1]=='A'||b[e-1]=='B'||b[e-1]=='C'){
				if(d[f-1]=='A'||d[f-1]=='B'||d[f-1]=='C'){
					cout<<1;
					if(d[f-1]-b[e-1]==1||d[f-1]-b[e-1]==-1)cout<<1;
					else cout<<0;
				}
				else cout<<"00";
			}
			if(b[e-1]=='E'||b[e-1]=='F'){
				if(d[f-1]=='E'||d[f-1]=='F'){
					cout<<1;
					if(d[f-1]-b[e-1]==1||d[f-1]-b[e-1]==-1)cout<<1;
					else cout<<0;
				}
				else cout<<"00";
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
}

