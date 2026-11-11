#include<bits/stdc++.h>
using namespace std;

const int MAXN = 500005;

int n;
long long m;
long long a[MAXN],b[MAXN];
bool k = 1;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	sort(a,a+n);
	
	for(int i=1;i<n;i++){
		b[i] = a[i] - a[i - 1];
		if(b[i] != b[i - 1] && i != 1) k = 0;
	}
	
	long long sum = 0,x = 0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			sum += b[j] * (long long)(j - i);
			if(sum > m){
				x = max(x,(long long)j - i);
				break;
			}
		}
		sum = 0;
	}
	cout<<x<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
