#include<bits/stdc++.h>

using namespace std;

long long n,m,a[5000005],sumn,tt[5000005],tong[5000005],ttde = 0;
long long step = 0,flag,ding;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i<n;i++){
		cin >> a[i];
		tt[i] = -1;
	}
	sumn = n;
	ding = 0;
	while(sumn--){
		//cout  << "//////////////" << sumn << endl;
		step = ding;
		ttde = 0;
		for(int i = 0;i<=n;i++){
			tt[i] = -1;
		}
		while(step < n){
			//cout << step << "///step" << endl;
			flag = -1;
			
			for(int i = 0;i<n;i++){
				if(tt[i] == a[step]){
					flag = i+1;
					break;
				}
			}
			//cout << flag << " find" << endl;
			//for(int i = 0;i<n;i++){
				//cout << tt[i] << " ";
			//}
			//cout << "////ԭʼ" << endl; 
			if(flag != -1){
				for(int i = flag;i<n;i++){
					tt[i] = -1;
				}
				ttde = flag-1;
			}
			//for(int i = 0;i<n;i++){
				//cout << tt[i] << " ";
			//}
			//cout << "/////update" << endl;
			//cout << ttde << "///med" << endl; 
			tt[ttde] = a[step];
			step++;
			ttde++;
			//for(int i = 0;i<n;i++){
				//cout << tt[i] << " ";
			//}
			//cout << "/////updatedfsasd" << endl;
		}
		for(int i = 0;i<=ttde;i++){
			tong[tt[i]]++;
		}
		//for(int i = 1;i<=m;i++){
			//cout << tong[i] << " ";
		//}
		//cout << "////tong" << endl;
		ding++;
	}
	for(int i = 1;i<=m;i++){
		cout << tong[i] << " ";
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
