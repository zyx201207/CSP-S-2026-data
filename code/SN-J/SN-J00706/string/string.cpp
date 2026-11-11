//朱毅然 陕西延安中学 SN-J00706
#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=0;
struct node{
	int a;
	char c;
} a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].a>>a[i].c;
	int l=1,r=n;
	while(l<r){
		if(a[l].c!=a[r].c) ans+=min(a[l].a,a[r].a);
		if(a[l].a<a[r].a){
			a[r].a-=a[l].a;
			l++;
		}else if(a[l].a==a[r].a){
			l++;
			r--;
		}else{
			a[l].a-=a[r].a;
			r--;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
