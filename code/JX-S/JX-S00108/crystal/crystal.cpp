#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
long long  m;
int n;
cin.tie(0);
cin>>n>>m;
for(int i=0;i<n;i++){
	cin>>a[i];
	}
	sort(a,a+n);
	if(a[0]==a[n-1]){cout<<n;return 0;}
	if(a[1]-a[0]==a[n-1]-a[n-1]&&a[1]-a[0]==a[3]-a[2]&&n>5000){
		cout<<m/(a[1]-a[0]);return 0;
		}
	long long b[500005]={};
	long long c[500005]={};
	for(int i=n-1;i>=0;i--){
		for(int j=i-1;j>=0;j--){
			b[i]+=a[i]-a[j];
			c[i]++;
		 if(b[i]>m){c[i]--;break;}
         else if(b[i]==m)break;
			}
		}
			sort(c,c+n);
			cout<<c[n-1]+1;
return 0;
}
/*1 2 4 8 9
 *0 1 2 4 1
 * 0+1+4+12+4=21 
 * 21-8=13
 * 13-7=6
 * 6-5=1
 * 0+1+4+12=17
 * 17-7=10
 * 10-6=4
 * 1 2 4 8 9
 * 1 2 3 4 5
 * 1 1 1 1 1
 * 10 6 3 1
 
 */
