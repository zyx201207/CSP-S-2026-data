#include<bits/stdc++.h>
using namespace std;
long long a[100005];
char b[100005];
long long a2[100005];
char b2[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,l=0,cnt=0;
	char x=' ';
	cin>>n;
	for(int i=1;i<=n;i++){
		int q;
		char c;
		cin>>q>>c;
		cnt += q;
		if(c == x){
			a[l] += q;
		}
		else{
			l++;
			a[l] += q;
			b[l] = c;
		}
		x = c;
	}
	long long r=0,cd=1;
	for(int i=1;i<=l;i++){
		if(r+a[i] <= cnt){
			r += a[i];
			a2[cd] = a[i];
			b2[cd++] = b[i];
		}
		else{
			a2[cd] = cnt-r;
			b2[cd] = b[i];
			a[i] -= a2[cd];
			cd++;
			for(int j=i;j<=l;j++){
				a[cd] = a[i];
				b[cd++] = b[i];
			}
		}
	}
	long long sum=0;
	long long i=1,j=l;
	while(i<j){
		long long mi=0;
		if(b2[i] != b2[j]){
			mi=min(a2[i],a2[j]);
			sum += mi;
			a2[i] -= mi;
			if(a2[i] == 0){
				i++;
			}
			a2[j] -= mi;
			if(a2[j] == 0){
				j--;
			}
		}
		else{
			mi=min(a2[i],a2[j]);
			a2[i] -= mi;
			if(a2[i] == 0){
				i++;
			}
			a2[j] -= mi;
			if(a2[j] == 0){
				j--;
			}
		}
	}
	cout<<sum;
	return 0;
} 
