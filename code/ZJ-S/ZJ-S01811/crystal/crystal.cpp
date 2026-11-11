#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    int m,n,ans=0;
    cin>>n>>m;
    long long i,a[n],q[n];
    int s[n];
    for(i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    q[0]=a[0];
    for(i=1;i<n;i++)q[i]=a[i]+q[i-1];
    for(i=0;i<n;i++)cout<<a[i]<<' ';
    //cout<<endl;
    for(i=0;i<n;i++)cout<<q[i]<<' ';
    //cout<<endl;
	for(i=0;i<n;i++){
		int l=i,r=n-1,mid,k=0;
		while(k<5){
			mid=(l+r)/2;
			if(mid<n-1){
				long long x=a[mid]*(mid-i+1)-q[mid]+q[i-1]*(i>0),y=a[mid+1]*(mid-i+2)-q[mid+1]+q[i-1]*(i>0);
				//cout<<x<<' '<<y<<' '<<mid<<',';
				if((x<=m)&&(y>m))break;
				if(x<=m)l=mid+1;
				if(y>m)r=mid-1;
				k++;
		    }
		    else break;
		}
		s[i]=mid-i+1;
		//cout<<"/"<<s[i]<<" "<<mid<<endl;
	}
	for(i=0;i<n;i++)ans=max(ans,s[i]);
	cout<<ans;
	return 0;
}

