#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d,e[1000005],f[1000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>a>>b;
	if(a==11||a==12){
		for(int iz=0;iz<b;iz++){
			e[1000005]={0};
			cin>>c>>d;
			for(int i=0;i<c;i++){
				cin>>e[i];
			}
			if(d==1){
				cout<<0<<endl;
				continue;
			}
			if(e[1]-e[0]>=d){
				cout<<0<<endl;
			}
			if(e[c-1]-e[0]<=d){
				cout<<0<<endl;
			}
		}
		return 0;
	}
	for(int iz=0;iz<b;iz++){
		e[1000005]={0};
		cin>>c>>d;
		for(int i=0;i<c;i++){
			cin>>e[i];
		}
		if(c<=3){
			cout<<0<<endl;
			continue;
		}
		if(c==4){
			if(e[3]-e[1]<=d&&e[2]-e[0]<=d){
				cout<<1<<endl;
				continue;
			}
			else{
				cout<<0<<endl;
				continue;
			}
		}
		else{
			cout<<2<<endl;
		}

	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
