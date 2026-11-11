#include <bits/stdc++.h>
using namespace std;
int a[400005];
char b[400005];
long long d[100];
bool c = 0,f = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,e = 0;
	cin >> n;
	for(int i = 1;i <= n;i++){
		e++;
		cin >> a[i] >> b[i];
		if(b[i] != b[i-1]){
			for(int j = 0;j <= e;j++){
				if(b[i-j] == b[1+j]&&a[i-j] == a[1+j]){
						if(b[i] == 'A'){
							d[1] += a[i];
						}else if(b[i] == 'B'){
							d[2] += a[i];
						}else if(b[i] == 'C'){
							d[3] += a[i];
						}else if(b[i] == 'D'){
							d[4] += a[i];
						}else if(b[i] == 'E'){
							d[5] += a[i];
						}else if(b[i] == 'F'){
							d[6] += a[i];
						}else if(b[i] == 'G'){
							d[7] += a[i];
						}else if(b[i] == 'H'){
							d[8] += a[i];
						}else if(b[i] == 'I'){
							d[9] += a[i];
						}else if(b[i] == 'J'){
							d[10] += a[i];
						}else if(b[i] == 'K'){
							d[11] += a[i];
						}else if(b[i] == 'L'){
							d[12] += a[i];
						}else if(b[i] == 'M'){
							d[13] += a[i];
						}else if(b[i] == 'N'){
							d[14] += a[i];
						}else if(b[i] == 'O'){
							d[15] += a[i];
						}else if(b[i] == 'P'){
							d[16] += a[i];
						}else if(b[i] == 'Q'){
							d[17] += a[i];
						}else if(b[i] == 'R'){
							d[18] += a[i];
						}else if(b[i] == 'S'){
							d[19] += a[i];
						}else if(b[i] == 'T'){
							d[20] += a[i];
						}else if(b[i] == 'U'){
							d[21] += a[i];
						}else if(b[i] == 'V'){
							d[22] += a[i];
						}else if(b[i] == 'W'){
						}else if(b[i] == 'X'){
							d[23] += a[i];
							d[24] += a[i];
						}else if(b[i] == 'Y'){
							d[25] += a[i];
						}else if(b[i] == 'Z'){
							d[26] += a[i];
						}
				}else if(b[i-j] == b[1+j]){
					
				}
				j++;
			}
		}
	}
	f = 0;
	for(int i = 1;i <= n;i++){
		f += a[i];
	}
	cout << f;
	return 0;
}
