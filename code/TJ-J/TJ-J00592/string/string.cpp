#include<bits/stdc++.h>
using namespace std;
pair<long long,char> a[200005];
char s[2000000000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i].first >> a[i].second;
	}
	long long id=0;
	for(int i=0;i<n;i++){
		long long y=a[i].first;
		for(long long j=0;j<y;j++){
			s[id]=a[i].second;
			id++;
		}
	}
	long long l=0,r=id-1,cnt=0;
	if(id%2==0){
		while(l-r!=1){
			if(s[l]!=s[r])cnt++;
			l++;
			r--;
		}
	}else{
		while(l!=r){
			if(s[l]!=s[r])cnt++;
			l++;
			r--;
		}
	}
	cout << cnt;
	fclose(stdin); 
	fclose(stdout); 
	return 0;
}
