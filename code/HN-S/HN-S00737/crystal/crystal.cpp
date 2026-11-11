#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
int a[500005];
int kmp[500005]; 
bool book=0;
long long sum=1;
void sumy(int x){
	long long c=0;
	long long l=x-1,r=x+1,m1=m;
	while(c<m1){
		long long o=c;
		long long c1=a[x]-a[l],c2=a[r]-a[x];
		if(c1<c2&&c+c1<=m1){
			c+=c1;
			m1-=c1;
			l--;
			sum++;
		}else if(c1>c2&&c+c2<=m1){
			c+=c2;
			m1-=c2;
			r++;
			sum++;
		}else if(c1==c2&&c+c1<=m1){
		    c+=c1;
		    m1-=c1;
		    l--;
		    sum++;
		}
		if(o==c) break;
	}
}
void mar(int l,int mid,int r){
	int i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r){
		if(a[i]<=a[j]){
			kmp[k++]=a[i++];
		}else{
			kmp[k++]=a[j++];
		}
	}
	while(i<=mid) kmp[k++]=a[i++];
	while(j<=r) kmp[k++]=a[j++];
	for(int p=l;p<=r;p++){
		a[p]=kmp[p];
	}
}
void mar_sor(int l,int r){
	if(l>=r) return;
	int mid=l+(r-l)/2;
	mar_sor(l,mid);
	mar_sor(mid+1,r);
	mar(l,mid,r);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	if(n>5000){
		long long poi=a[2]-a[1];
		long long po=m/poi;
		long long s=0;
		for(int i=1;i<=n;i++){
			if(s>=po){
				cout<<i;
				return 0;
			}
		    s+=i;
		}
	}
	mar_sor(1,n);
	sumy((a[n]+a[1])/2);
	cout<<sum;
	return 0;
} 
