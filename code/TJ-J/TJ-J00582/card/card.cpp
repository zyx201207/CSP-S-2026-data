#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m;
int a[N],cnt[N],del;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		for(int j=0;j<i;j++){
			if(a[j]==a[i])del=i;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
