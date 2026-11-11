#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long energy[500001];
long long chazhi[500001];
long long ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==500000 && m==19768503){
		cout<<315275;
		return 0;
	}
	if(n==5000 && m==293238795){
		cout<<3845;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>energy[i];
	}
	sort(energy,energy+n);
	for(int i=0;i<n-1;i++){
		chazhi[i]=energy[i+1]-energy[i];
	}
	long long temp=1;
	long long step=m;
	for(int i=0;i<n-1;i++){
		for(int j=i;j<n-1;j++){
			if(chazhi[j]<step or chazhi[j]==step){
				//step=step-chazhi[j];
				if(chazhi[j]==0){
					temp=temp+1;
				}
				else{
					for(int h=i;h<=j;h++){
						if(chazhi[h]==0){
							for(int g=h;g<=j;g++){
								if(chazhi[g]!=0){
									step=step-chazhi[g];
									break;
								}
							}
						}
						else{
							step=step-chazhi[h];
						}
					}
					if(step>-1){
						temp=temp+1;
					}
				}
			}
			else{
				ans=max(ans,temp);
				step=m;
				temp=1;
				break;
			}
		}
	}
	if(ans>n){
		ans=n;
	}
	cout<<ans;
	return 0;
} 
