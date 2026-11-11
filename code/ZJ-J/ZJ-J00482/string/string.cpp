#include<bits/stdc++.h>
using namespace std;
long long x[200005];
char w[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,h=0,t,cnt=0;
	char a;
	cin>>n;
	while(n--){
		cin>>t>>a;
		h+=t;
		if(a==w[cnt]){
			x[cnt]+=t;
		}else{
			cnt++;
			w[cnt]=a;
			x[cnt]=t;
		}
	}
	t=cnt;
	cnt=0;
	int l=1,r=t;
	while(r>=l){
		if(w[l]==w[r]){
			if(x[l]>=x[r]){
				x[l]-=x[r];
				r--;
			}else{
				x[r]-=x[l];
				l++;
			}
		}else{
			if(x[l]>=x[r]){
				x[l]-=x[r];
				cnt+=x[r];
				r--;
			}else{
				x[r]-=x[l];
				cnt+=x[l];
				l++;
			}
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
