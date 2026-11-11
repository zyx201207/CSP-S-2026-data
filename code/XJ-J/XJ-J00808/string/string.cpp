#include <bits/stdc++.h> 
using namespace std;
const int N=1e5+9;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long a[N],sum=0;
	string c[N];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int j=n;
	for(int i=1;i<=n;i++){
		if(i>=j)break;
		if(c[i]==c[j] && i+j!=3){
			sum+=max(a[i],a[j])-min(a[i],a[j]);
			if(max(a[i],a[j])-min(a[i],a[j])>=a[j-1]){
				j--;
			}
			else if(max(a[i],a[j])-min(a[i],a[j])>=a[i+1]){
				i++;
			}
		}
		else if(c[i]!=c[j]){
			
			if(c[i+1]==c[j] && a[i]<=max(a[i+1],a[j])-min(a[i+1],a[j])){
				sum+=max(a[i+1],a[j])-min(a[i+1],a[j]);
				i++;
			}
			else if(c[i]==c[j-1] && a[i]<=max(a[i],a[j-1])-min(a[i],a[j-1])){
				sum+=max(a[i],a[j-1])-min(a[i],a[j-1]);
				j--;
			}
			else sum+=max(a[i],a[j]);
		}
		j--;
	}
	cout<<sum;
	
	return 0;
}
