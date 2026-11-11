#include<bits/stdc++.h>
using namespace std;
long long aa[200010];
char chb[10];
char cha[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ans=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>aa[i]>>cha[i];
	}
	long long ka,kb;
	int shufu=n,i=1; 
	ka=aa[i];
	kb=aa[n];
	while(shufu>i){
		if(ka<kb){
			if(cha[i]==cha[shufu]){
				ans+=0;
				kb-=ka;
				i++;
				ka=aa[i];
			}
			else{
				ans+=ka;
				kb-=ka;
				i++;
				ka=aa[i];
			}
		}
		else if(ka==kb){
			if(cha[i]!=cha[shufu]){
				ans+=ka;
				i++;
				shufu--;
				ka=aa[i];
				kb=aa[shufu];
			}
			else{
				ans+=0;
				i++;
				shufu--;
				ka=aa[i];
				kb=aa[shufu];
			}
		}
		else{
			if(cha[i]==cha[shufu]){
				ans+=0;
				ka-=kb;
				shufu--;
				kb=aa[shufu];
			}
			else{
				ans+=kb;
				ka-=kb;
				shufu--;
				kb=aa[shufu];
			}
		}
	}
	cout<<ans;
	return 0;
} 
