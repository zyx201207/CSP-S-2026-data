//SN-J00779 王梓翰 西安交通大学附属中学
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
char c[N];
int b[N];
char d[N];
#define int long long
int n;
int L;
int p,q;
int ans;
signed main(void){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		L+=a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=a[n-i+1];
		d[i]=c[n-i+1];
	}
	p=q=1;
	int TMP=L/2;
	int TMP2=0;
	int st=0;
	for(int i=1;i<=n;i++){
		TMP2+=b[i];
		if(TMP2>=TMP){
			st=i;
			break;
		}
	}
//	cout<<TMP<<" "<<st<<endl;
	while(q<st){
//		cout<<p<<" "<<q<<" "<<a[p]<<" "<<b[q]<<endl;
		if(a[p]>b[q]){
			ans+=(c[p]!=d[q])*b[q];
			a[p]-=b[q];
			q++;
			
		}else if(a[p]<b[q]){
			ans+=(c[p]!=d[q])*a[p];
			b[q]-=a[p];
			p++;
		}else{
			ans+=(c[p]!=d[q])*a[p];
			p++; q++;
		}
	}
	int t=TMP2-TMP;
	b[q]-=t;
	while(b[q]){
		if(a[p]>b[q]){
			ans+=(c[p]!=d[q])*b[q];
			break;
		}else if(a[p]<b[q]){
			ans+=(c[p]!=d[q])*a[p];
			
			b[q]-=a[p];
			p++;
		}else{
			ans+=(c[p]!=d[q])*a[p];
			break;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//T2 : 0R4NG3/Y3110W
//△(mind)=114514
//75min ...... 
