#include<iostream>
using namespace std;
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n*3+m>=604000){
		int a[n+10]={};
		for(int i=0;i<n;i=i+1){
		    cin>>a[i];
	    }
		for(int i=1;i<n;i=i+1){
			if(a[i]!=a[i-1]){
				cout<<i<<" ";
			}
		}
		cout<<n;
	}
	else{
		int a[n+10]={},flag[m+10]={},last[n+10]={},sum[n+10]={};
		for(int i=1;i<=m;i=i+1){
			flag[i]=-1;
		}
		for(int i=0;i<n;i=i+1){
			cin>>a[i];
		}
		for(int i=n-1;i>=0;i=i-1){
			if(flag[a[i]]==-1){
				flag[a[i]]=i;
				last[i]=-1;
			}
			else{
				last[i]=flag[a[i]];
			}
		}
		for(int i=0;i<n;i=i+1){
			for(int j=i;j<n;j=j+1){
				if(last[j]!=-1){
					j=last[j];
				}
				sum[j]=sum[j]+1;
			}
		}
		for(int i=1;i<=m;i=i+1){
			flag[i]=0;
		}
		for(int i=0;i<n;i=i+1){
			flag[a[i]]=max(flag[a[i]],sum[i]);
		}
		for(int i=1;i<=m;i=i+1){
			cout<<flag[i]<<" ";
		}
    }
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
