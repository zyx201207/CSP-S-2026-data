#include<bits/stdc++.h>
using namespace std;
int n;
long long int cnt=0;
struct node{
	long long a;
	char c;
} w[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>w[i].a>>w[i].c;
	}
	int l=1,r=n;
	long long rest=0;
	while(l<=r){
		if(w[l].c!=w[r].c){
			if(w[l].a>w[r].a){
				cnt+=w[r].a;
				w[l].a=w[l].a-w[r].a;
				r--;
			}
			else if(w[l].a<w[r].a){
				cnt+=w[l].a;
				w[r].a=w[r].a-w[l].a;
				l++;
			}
			else{
				cnt+=w[l].a;
				l++;
				r--;
			}
		}
		else if(w[l].c==w[r].c){
			if(w[l].a>w[r].a){
				w[l].a=w[l].a-w[r].a;
				r--;
			}
			else if(w[l].a<w[r].a){
				w[r].a=w[r].a-w[l].a;
				l++;
			}
			else{
				l++;
				r--;
			}
		}

	}
	cout<<cnt;
    return 0;
}

