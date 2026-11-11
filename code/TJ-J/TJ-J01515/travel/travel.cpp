#include <iostream>
using namespace std;



int main()
{
    freopen("travel.in ","r",stdin);
	freopen("travel.out","w",stdout);
	int n1,n2,j = 1;
    char n11,n12,n13,n21,n22,n23;
    cin >> n1 >> n11 >> n12 >> n13 >> n2 >> n21 >> n22 >> n23;
    for(int t = 0;t <= 0;t++)
	{
		if (n1 != n2){
			cout << "0000";
			break;
		}
		
		if(n1 == n2){
        	cout << "1";//
        	if(n11 == n21 && n12 == n22){
        		cout << "1";
        		char a[3] = {'A','B','C'};
        		char b[2] = {'E','F'};
        		if(n13 == a[1] || n13 == a[0] || n13 == a[2]){
        			if(n23 == a[0] || n23 == a[1] || n23 == a[2]){
        				cout << "1";
        				if(n13 == a[0] && n23 == a[1] || n13 == a[1] && n23 == a[2]){
        					cout << "1";
						}
						else{
							cout << "0";
							break;
						}
					}
				}
				else{
					cout << "00";
					break;
				}
				if(n13 == b[0] || n13 == b[1]){
					if (n23 == b[0] || n23 == b[1]){
						cout << "1";
						break;
					}
				}
				else{
					cout << "00";
					break;
				}
				}
			}
			else{
				cout << "000";
			}
    	}
    fclose(stdin);
	fclose(stdout);	
    return 0;
}

