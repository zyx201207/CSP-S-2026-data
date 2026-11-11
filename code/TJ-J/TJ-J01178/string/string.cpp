#include <bits/stdc++.h>
using namespace std;

int shu[200010];
string chuan[10000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long cnt,sum =0,num=0,xian = 1;
	cin >> cnt;
	string zifuchuan[cnt+10];
	for(int a = 1;a<=cnt;a++){
		cin>>shu[a]>>zifuchuan[a];
		for(int j = a ;j <= a+shu[a]-1;j++){
				chuan[j] = zifuchuan[a];
				num++;
				
			}
	}
	//²âÊÔ

	 
	for(int i = 1;i<=(num+1)/2;i++){
		if(chuan[i] == chuan[num-i]){
			continue;
			
			
		}
		
		sum++;

	}
	cout << sum;
	return 0;
}
//Trick||Treat!4



