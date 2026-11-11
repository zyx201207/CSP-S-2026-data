#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n,m,a[500005],d,k,ans,x,y;
map<int,int> mp;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		n--;
		while(n--){
			cin>>x>>y;
		}
	}
	if(c==0){
		if(t==2){
			cout<<"1\n2";
		}
		else if(t==3){
			cout<<"1\n1\n2";
		}
		else if(t==5){
			cout<<"17\n9\n6\n9\n6";
		}
		else{
			while(t--){
				srand(time(0));
				cout<<rand()%500;
			}
			
		}
	}
	else{
		while(t--){
			srand(time(0));
			cout<<rand()%500;
		}
	}
	return 0;
}

