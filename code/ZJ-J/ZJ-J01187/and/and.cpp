#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(m==2){
		int maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				sum=a[i]&a[j];
				maxn=max(maxn,sum);
			}
		}
		cout<<maxn;
		fclose(stdin);
	    fclose(stdout);
	    return 0;
	}
	if(m==n-1){
		int pre[200005],pfx[200005],maxn;
		pre[1]=a[1];pfx[n]=a[n];
		for(int i=2;i<=n-1;i++)
		    pre[i]=pre[i-1]&a[i];
		for(int i=n-1;i>=2;i--)
		    pfx[i]=pfx[i+1]&a[i];
		maxn=pfx[2];
        for(int i=2;i<=n;i++){
        	if(i==n) maxn=max(maxn,pre[i-1]);
        	else{
        		sum=pre[i-1]&pfx[i+1];
        		maxn=max(maxn,sum);
			}
		}
		cout<<maxn;
		fclose(stdin);
	    fclose(stdout);
	    return 0;
	}
	sort(a+1,a+1+n,greater<int>());
	sum=a[1];
	for(int i=1;i<=m;i++)
		sum&=a[i];
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
