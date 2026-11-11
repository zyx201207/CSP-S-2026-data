#include<bits/stdc++.h>
using namespace std;
int tmp[1010];
char nxt[1010];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	tmp['A']=1;
	tmp['B']=1;
	tmp['C']=1;
	tmp['D']=2;
	tmp['F']=2;
	
	nxt['A']='B';
	nxt['B']='C';
	nxt['C']='D';
	nxt['D']='F';
	nxt['F']=' ';
	string a,b,x,y;
	cin>>a>>x>>b>>y;
	string t1="",t2="";
	t1+=x[0];
	t1+=x[1];
	t2+=y[0];
	t2+=y[1];
	int u=x[2],v=y[2];
	if(a==b){
		cout<<"1";
		if(t1==t2){
			cout<<"1";
			if(tmp[u]==tmp[v]){
				cout<<"1";
				if(nxt[u]==y[2]||nxt[v]==x[2]){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
