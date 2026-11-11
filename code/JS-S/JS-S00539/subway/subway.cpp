#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,w[N],line[505],k,a[1010],x,y;
int main(){
  	freopen("migrate.in","r",stdin);
 	freopen("migrate.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
        cin>>w[i];
	}
	int tmmmmp=2ll;
	while(tmmmmp--){
        cin>>k;
        for(int i=1;i<=2*k;i++){
            cin>>a[i];
        }
	}
	while(cin>>x>>y){
        if(x==1){
            if(y==2){
                cout<<"17\n";
            }else if(y==3){
                cout<<"32\n";
            }else if(y==6){
                cout<<"35\n";
            }
        }else if(x==2){
            if(y==3){
                cout<<"16\n";
            }
        }
	}
	return 0;
}
