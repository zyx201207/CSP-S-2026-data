//西安辅轮中学 仲昶霖 SN-J00818 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a,b[10005];
	cin >> n >> m;
	for(int i=0 ;i<n;i++){
		cin >> a;
		b[i]=a;
	} 
	for(int i=0;i<n ;i++){
		for(int j=0;j<n;j++){
			if(b[i]==b[j]){
				for(int p=0;p<j-i;p++){
					b[p]=0;
				}
			}
		}
	}
	return 0;
}

