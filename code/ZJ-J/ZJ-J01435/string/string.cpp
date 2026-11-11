#include<bits/stdc++.h>
using namespace std;
long long sum;
struct node{
	int a;
	char b; 
}x[200050];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int l=1,r=n;
	for(int i=1;i<=n;i++){
		cin>>x[i].a>>x[i].b;
	}
	for(int i=1;i<=n;i++){
		if(l>=r){
			break;
		}
		if(x[l].b==x[r].b){
			if(x[l].a==x[r].a){
				l++;
				r--;
			}
			else{
				if(x[l].a>x[r].a){
					x[l].a-=x[r].a;
					r--;
				}
				else{
					x[r].a-=x[l].a;
					l++;
				}
			}
		}
		else{
			if(x[l].a==x[r].a){
				sum+=x[l].a;
				l++;
				r--;	
			}
			else{
				if(x[l].a>x[r].a){
					sum+=x[r].a;
					x[l].a-=x[r].a;
					r--;
				}
				else{
					sum+=x[l].a;
					x[r].a-=x[l].a;
					l++;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
