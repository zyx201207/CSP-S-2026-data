#include<bits/stdc++.h>
using namespace std;
void _file(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
}
long long n,ans;
long long a[200010];char b[200010];
int main(){
	_file();
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	long long l=1,r=n;
	while(r>l){
		if(b[l]==b[r]){
			if(a[l]>a[r]) a[l]-=a[r],r--;
			else if(a[r]>a[l]) a[r]-=a[l],l++;
			else l++,r--;
			continue;
		}else{
			if(a[l]>a[r]) ans+=a[r],a[l]-=a[r],r--;
			else if(a[r]>a[l]) ans+=a[l],a[r]-=a[l],l++;
			else ans+=a[l],l++,r--;
			continue;			
		}
	}
	cout<<ans;
	return 0;
}

/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
