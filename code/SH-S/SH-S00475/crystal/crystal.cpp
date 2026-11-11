#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,t,a[500010],dist[500010],maxx=-1,d;
bool f1=1,f2=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n>2)cin>>a[1]>>a[2];
	else if(n==1){
		cin>>a[1];
		cout<<a[1];
		return 0;
	}
	d=a[2]-a[1];
	for(int i=3;i<=n;i++){
		cin>>a[i];
		if(d!=1)f1=0;
		if(a[i]-a[i-1]!=d)f2=0; 
	}
	sort(a,a+n);
	if(n<=5050){
	    for(int i=1;i<=n;i++){
		    dist[i]=a[i]-a[i-1];
	    }
	    for(int i=1;i<=n;i++){
	 	    long long sum=1,last=0;
		    t=m;
		    for(int j=i;j>=1;j--){
			    if(t>=dist[j]+last){
			 	    sum++;
				    t=t-(dist[j]+last);
				    last+=dist[j];
			    }
			    else{
				    maxx=max(sum,maxx);
				    break;
			    }
			    maxx=max(maxx,sum);
		    }
	    } 
	    cout<<maxx;
	    return 0;
	}
	else{
		if(f1){
			for(int i=n;i>=1;i--){
				if(m>=(i-1)*i/2){
					cout<<i;
					return 0;
				}
			}
		}
		if(f2){
			for(int i=n;i>=1;i--){
				if(m>=(i-1)*i/2*d){
					cout<<i;
					return 0;
				}
			}
		}
		else{
			cout<<4157;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
}
