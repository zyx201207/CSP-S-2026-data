#include<bits/stdc++.h>
using namespace std;
int n,k;
long long sum;
//char a[200000005];
struct str{
	long long x;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char d='0';
    for(int i=1;i<=n;i++){
		long long m;
		char e;
		cin>>m>>e;
		if(e==d){
			a[k].x+=m;
			continue;
	    }
	    a[++k].x=m;
	    a[k].c=e;
	    d=e;
	}
	//cout<<a[1].x<<" "<<a[2].x<<endl;
	int l=1,r=k;
	while(l<r){
		if(a[l].c==a[r].c){
			if(a[l].x==a[r].x){
			    l++;
			    r--;
	        }else if(a[l].x>a[r].x){
				a[l].x-=a[r].x;
				r--;
	        }else{
			    a[r].x-=a[l].x;
			    l++;
			}
	    }else{
		    if(a[l].x==a[r].x){
				sum+=a[l].x;
			    l++;
			    r--;
	        }else if(a[l].x>a[r].x){
				a[l].x-=a[r].x;
				sum+=a[r].x;
				r--;
	        }else{
			    a[r].x-=a[l].x;
			    sum+=a[l].x;
			    l++;
			}
		}
    }
    cout<<sum;
	return 0;
}
