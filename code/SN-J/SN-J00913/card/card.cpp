#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500005],SCGLENTH,DesktopLENTH;
queue<long long>ZZZ;
stack<long long>Desktop,SCG;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ZZZ.push(a[i]);
	}for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int k=0;k<i;k++){
				ZZZ.pop();
			}
			for(int k=0;k<j;k++){
				if(Desktop.top()==a[j]){
					for(int l=0;l<j;l++){
						SCG.pop();
						DesktopLENTH--;
					}Desktop.pop();
					SCGLENTH=0;
				}
				SCG.push(Desktop.top());
				SCGLENTH++;
				Desktop.pop();
			}for(int k=0;k<SCGLENTH;k++){
				Desktop.push(SCG.top());
				SCG.pop();
			}
			Desktop.push(ZZZ.front());
			DesktopLENTH++;
			ZZZ.pop();
		}cout<<DesktopLENTH<<' ';
	}
	return 0;
}
