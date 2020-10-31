#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define FREE -1
#define WALL 2000
#define START 1000
#define STEP 0


#define N 15
#define M 20

void print(int g[N][M]){
        printf("\n");
    int i,j;
    for(i=0; i<N; i++){
        for(j=0;j<M; j++)
            printf("%4d ", g[i][j]);
        printf("\n");
    }
        printf("\n");
}


void inizialize(int g[N][M], int ie,int je){

    int i,j;
    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
            if(i==0 || i==N-1 || j==0 || j==M-1)
                g[i][j] = WALL;
            else if(g[i][j] == FREE)
                g[i][j] = pow(i-ie,2) + pow(j-je,2);
        }
    }
}

void find_path(int g[N][M],int i,int j){
    
    if(g[i][j]==0)
        return;


    int a,b;
    int im=i-1, jm=j-1, m=g[im][jm];
    for(a=i-1; a<=i+1; a++){
        for(b=j-1; b<=j+1; b++){
            if(a==i && b==j)
                continue;       // skip current cell     
            if(g[a][b]<m){
                m=g[a][b]; im=a; jm=b;
           }
        }
    }
    
#ifdef DEBUG
    print(g);
    scanf("%*s");
#endif
    
    if(g[im][jm] >= g[i][j])
        g[i][j]++;
    find_path(g,im,jm);
}


int main(int argc, char **argv){
    

    int g[N][M] = {
//        { WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL  },

/*
        { FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE  },
        { FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE  },
        { FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE  },
        { FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE  },
        { FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE  },
        { FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE  },
        { FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE  },
        { FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE  },
        { FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE  },
        { FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE  },
        { FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE  },
        { FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE  },
        { FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE  },
        { FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE  },
        { FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE  }
*/
        { FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE  },
        { FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE  },
        { FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE  },
        { FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE  },
        { FREE, FREE, FREE, FREE, WALL, WALL, WALL, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE  },
        { FREE, FREE, FREE, FREE, FREE, FREE, WALL, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE  },
        { FREE, FREE, FREE, FREE, FREE, FREE, WALL, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE  },
        { FREE, FREE, FREE, FREE, FREE, FREE, WALL, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE  },
        { FREE, FREE, FREE, FREE, WALL, WALL, WALL, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE  },
        { FREE, FREE, FREE, FREE, FREE, FREE, WALL, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE  },
        { FREE, FREE, FREE, FREE, WALL, WALL, WALL, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE  },
        { FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE  },
        { FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE  },
        { FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE  },
        { FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE  }
    };
    

    int is=9; // i_start
    int js=2; // j_start;
    int ie=8;
    int je=7;
    //g[is][js]=START;
    
    print(g);

    inizialize(g,ie,je);
    print(g);
    find_path(g,is,js);
    print(g);



    return 0;
}
