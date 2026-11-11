#include<bits/stdc++.h>
using namespace std;
long long int n,ans=0;
struct St{
	char b;
	long long int a;
}x[2000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&x[i].a,&x[i].b);
	}
	int l=0,r=0;
	for(int i=1;i<=n;i++){
		if(x[i-l].b!=x[n-i+1+r].b){
			if(x[i-l].a==x[n-i+1+r].a){
				ans+=x[i-l].a;
				x[i-l].a=0;
				x[n-i+1+r].a=0;
			}else if(x[i-l].a>x[n-i+1+r].a){
				ans+=(x[i-l].a-x[n-i+1+r].a);
				x[i-l].a=x[i-l].a-x[n-i+1+r].a;
				x[n-i+1+r].a=0;
				l++;
			}else{
				ans+=(x[n-i+1+r].a-x[i-l].a);
				x[n-i+1+r].a=x[n-i+1+r].a-x[i-l].a;
				x[i-l].a=0;
				r++;
			}
		}else if(x[i-l].b==x[n-i+1+r].b&&x[i-l].a!=x[n-i+1+r].a){
			bool bol=(x[i-l].a>x[n-i+1+r].a);
			if(bol){
				l++;
				x[i-l].a=x[i-l].a-x[n-i+1+r].a;
				x[n-i+1+r].a=0;
			}else{
				r++;
				x[n-i+1+r].a=x[n-i+1+r].a-x[i-l].a;
				x[i-l].a=0;
			}
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
