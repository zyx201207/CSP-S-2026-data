#include<bits/stdc++.h>
using namespace std;
const int maxx=2e5+5; 
int n;
long long l;
long long a[maxx];
char c[maxx];
int id;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&c[i]);
		l+=a[i];
	}
	for(int i=1;i<=n&&!id;i++){
		ans+=a[i];
		if(l%2==0){
			if(ans==l/2){
				id=i;
				break;
			}
			if(ans>l/2){	
				id=i;
				n++;
				long long add=ans-l/2;
				a[i]-=add;
				a[n]=add;
				c[n]=c[i];
				break;
			}
		}
		else{
			if(ans==l/2){
				id=i;
				a[i+1]--; 
				break;
			}
			if(ans>l/2){
				id=i;
				long long add=ans-l/2;
				if(add==1){
					a[i]--;
					break;
				}
				else{
					a[i]-=add;
					add--;
					n++;
					a[n]=add;
					c[n]=c[i];
					break;
				}
			}
		}
	}
	ans=0;
	int id1=1,id2=n;
	while(id1<=id){
		int add=a[id1];
		long long tot=0;
		while(tot<add){
			if(tot+a[id2]<=add){
				tot+=a[id2];
				if(c[id1]!=c[id2]){
					ans+=a[id2];
				}
				id2--;
			} 
			else{
				long long pyi=add-tot;
				a[id2]-=pyi;
				if(c[id1]!=c[id2]){
					ans+=pyi;
				} 
			}
		}
		id1++;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
