#include<iostream>
#include<stack>
using namespace std;
int n,m;
int a[500005];
bool in[100005];
int cnt[100005];
int s[100005],top;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]); 
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int x=a[j];
			if(in[x]){
				while(s[top]!=x){
					in[s[top]]=0;
					top--;
				} 
				top--;
			}
			s[++top]=x;
			in[x]=1;
		}
		while(top){
			cnt[s[top]]++;
			in[s[top]]=0;
			top--;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",cnt[i]);
	}
	return 0; 
} 
