#include<bits/stdc++.h>
int a[500005],b[500005];
int main(){
    using namespace std;
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long n,m;
	cin>>n>>m;
	for(long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(long i=0;i<n;i++){
        b[i]=a[0]-a[i];
	}
	long ma=0;
	for(long i=0;i<n;i++){
        long k=m;
        long c=0;
        long z=a[i]-a[0];
        for(long j=0;j<=i;j++){
            if(b[j]+z<=k){
                c++;
                k-=b[j]+z;
            }
            else{
                break;
            }
        }
        if(ma<c){
            ma=c;
        }
        else{
            break;
        }
	}
	cout<<ma;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
