#include<bits/stdc++.h>
using namespace std;
struct node{
	long long b;
	char c;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>a[i].b>>a[i].c;
	}
	long long sum=0;
	int l=1,r=n;
	while(l<r){
		if(a[l].c==a[r].c){
			if(a[l].b>a[r].b){
				a[l].b-=a[r].b;
				r--;
			}
			else if(a[l].b<a[r].b){
                a[r].b-=a[l].b;
                l++;
			}
			else{
                l++;
                r--;
			}
		}
		else{
            if(a[l].b<a[r].b){
                sum+=a[l].b;
                a[r].b-=a[l].b;
                l++;
            }
            else if(a[l].b>a[r].b){
                sum+=a[r].b;
                a[l].b-=a[r].b;
                r--;
            }
            else{
                sum+=a[l].b;
                l++;
                r--;
            }
		}
	}
	cout<<sum;
    return 0;
}
