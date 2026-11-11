#include <bits/stdc++.h>
using namespace std;

long long L[200045];
string c[200045];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0,head=0,tail;
	cin>>n;
	tail=n-1;
	for(int i=0;i<n;i++){
		cin>>L[i]>>c[i];
	}
	while(head<=tail && head<n/2+1 && tail>n/2-1){
		if(c[head]!=c[tail]){
			sum+=min(L[head],L[tail]);
			if(L[head]>L[tail]){
				L[head]=L[head]-L[tail];
				tail--;
			}
			else if(L[head]==L[tail]){
				head++;
				tail--;
			}
			else{
				L[tail]=L[tail]-L[head];
				head++;
			}
		}
		else{
			sum+=max(L[head],L[tail])-min(L[head],L[tail]);
			if(L[head]==L[tail]){
				head++;
				tail--;
			}
			else{
				if(L[head]>L[tail]){
					L[head]=L[head]-L[tail];
					tail--;
				}
				else{
					L[tail]=L[tail]-L[head];
					head++;
				}
			}
		}
	}
	cout<<sum<<endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
