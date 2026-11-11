include<bits/stdc.++h>

using namespace std;
int main(){
    freopen("travel.in","r",std.in);
    fclose("travel.out","w",std.out);
    int c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        cout << 1;
        if(s1 == 01A || s1 == 01C){
            cout << 1;
            if(s2 == 01D){
                cout << 00;
            }
            else{
                cout << 1;
                if(s2 == 01B){
                    cout << 1;
                }
                else{
                    cout << 0;
                }
            }
        }    
        else{
            cout << 000;
        }
    }    
    else{
        cout << 0000;
    }

    reture 0;
}

