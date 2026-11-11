
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false)
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		int s,t,sum=0;
		cin>>s>>t;
		for(int j = s;j<=t;j++){
			if(j%7==0){
				sum++;
			}
			else{
				int d = j;
				while (d){
					if(d%10==7){
						sum++;
						break;
					}
					d/=10;
				}
			}
		
		}
		cout<<sum<<endl;
	}
	return 0;
}
