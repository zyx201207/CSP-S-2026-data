#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll axis[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int k=0;k<t;k++){
		ll n,d;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>axis[i];
		}
		ll cnt=0;
		for(int i=0;i<n;i++){
			for(int j=i+d+1;j<n;j++){
				if(axis[j]-axis[j-1]>d){
					continue;
				}
				int steps;
				if((j-i+1)%d==0){
					steps=(j-i+1)/d;
				}else{
					steps=((j-i+1)/d)+1;
				}
				int chkstep=-1;
				if(j-i+1<2*d+1){
					for(int b=2;b<=d;b++){
						if(b!=d){
							for(int x=i;x<=j;x+=b){
								chkstep++;
							}
						}
						if(chkstep==steps){
							break;
						}else{
							cnt++;
							break;
						}
					}
				}
				
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
