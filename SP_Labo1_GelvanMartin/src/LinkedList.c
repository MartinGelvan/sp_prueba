#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this=(LinkedList*)malloc(sizeof(LinkedList)); //reservo y asigno de forma dinamica
    if(this!=NULL) //verifico si this es distinto de NULL
    {
    	this->size=0; //le ingreso 0 en el tamaño del array ya que es nueva y no contiene nada
    	this->pFirstNode=NULL; //Le asigno al pFirstNode NULL ya que este no contiene nada
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
    	returnAux=this->size; //me guardo la cantidad de elementos en returnAux
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* auxNodo= NULL;
    int tam;
    int i;

    tam=ll_len(this); //me traigo el tamaño del array

    if(this!=NULL && nodeIndex>-1 && nodeIndex<tam) //Verifico que this sea distinto de NULL, que el indice del nodo sea mayor a -1 y que el indice sea menor al tamaño
    {
    	auxNodo=this->pFirstNode; //guardo el primer nodo a auxNode
    	for(i=0;i<nodeIndex;i++)
    	{

    		auxNodo=auxNodo->pNextNode;  //guardo el siguiente nodo del auxiliar en auxNodo


    	}

    }

    return auxNodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	Node* nuevoNodo;
	int returnAux = -1;
	Node* anterior;

	if(this!=NULL)
	{
		if(nodeIndex>-1 && nodeIndex <(ll_len(this)+1))
		{
			nuevoNodo=(Node*)malloc(sizeof(Node)); //reservo y asigno memoria en memoria dinamica

			if(nuevoNodo!=NULL) //verifico que nuevoNodo sea distinto de NULL
			{
				nuevoNodo->pElement=pElement; //guardo el pElement en el elemento del nuevo nodo
				nuevoNodo->pNextNode=NULL; //el proximo nodo del nuevo nodo apunta a NULL

				if(nodeIndex==0) //si el indice del nodo es 0 entonces....
				{
					nuevoNodo->pNextNode= this->pFirstNode; //guardo el primer nodo en el siguiente nodo del nuevo nodo
					this->pFirstNode=nuevoNodo; //guardo el nuevo nodo en el primer nodo

				}else if(nodeIndex>0 && nodeIndex < ll_len(this))
				{
					anterior=getNode(this, nodeIndex-1);

					if(anterior!=NULL)
					{
						nuevoNodo->pNextNode=anterior->pNextNode;
						anterior->pNextNode=nuevoNodo;

					}
				}else
				{
					nuevoNodo->pNextNode=NULL;
					anterior=getNode(this, nodeIndex-1);
					anterior->pNextNode=nuevoNodo;

				}
				this->size++;
				returnAux=0;
			}
		}

	}


    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)
    {

    	if((addNode(this, ll_len(this), pElement))==0)
		{
    		returnAux=0;
		}
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* nodoConseguido;
    int tam= ll_len(this);

    if(this!=NULL && index>-1 && index<tam)
    {
    	nodoConseguido=getNode(this, index);

    	if(nodoConseguido!=NULL)
    	{
    		returnAux=nodoConseguido->pElement;
    	}
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* nodoConseguido;

    if(this!=NULL)
    {
    	nodoConseguido=getNode(this, index);

    	if(nodoConseguido!=NULL)
    	{
    		nodoConseguido->pElement=pElement;
    		returnAux=0;
    	}


    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* nodoActual;
    Node* nodoAnterior;
    Node* nodoSiguiente;

    if(this!=NULL && index>-1 && index<(ll_len(this)+1))
    {

    	nodoActual=getNode(this, index);
    	nodoAnterior=getNode(this, index-1);
    	nodoSiguiente=getNode(this, index+1);

    	if(nodoActual!=NULL)
    	{

    		if(index==0)
    		{
    			this->pFirstNode=nodoSiguiente;
    			free(nodoActual);
    			nodoActual=NULL;
    			this->size--;
    			returnAux=0;

    		}else if(index>0 && index<ll_len(this))
    		{

    			nodoAnterior->pNextNode=nodoSiguiente;
    			free(nodoActual);
    			nodoActual=NULL;
				this->size--;
				returnAux=0;


    		}else //En caso que el indice sea el tamaño
    		{
    			nodoAnterior->pNextNode=NULL;
    			free(nodoActual);
    			nodoActual=NULL;
    			this->size--;
    			returnAux=0;

    		}
    	}


    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
    	while(ll_len(this)!=0)
    	{
    		ll_remove(this,ll_len(this));
    		this->size--;
    	}

    	if(ll_len(this)==0)
    	{
    		returnAux=0;
    	}

    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
    	ll_clear(this);
    	free(this);
    	returnAux=0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    Node* nodo;

    if(this!=NULL)
    {
    	for(i=0; i< ll_len(this);i++)
    	{
    		nodo=getNode(this, i);

    		if(nodo!=NULL && nodo->pElement==pElement)
    		{
    			returnAux=i;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
    	if(ll_len(this)==0)
    	{
    		returnAux=1;
    	}else
    	{
    		returnAux=0;
    	}

    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;


    if(this!=NULL && index>-1 && index<(ll_len(this)+1))
    {
    	addNode(this, index, pElement);

    	returnAux=0;

    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;


    if(this!=NULL && index>-1 && index<(ll_len(this)+1))
    {
    	returnAux=ll_get(this, index);

    	ll_remove(this, index);

    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int index;

    if(this!=NULL)
    {
    	index=ll_indexOf(this, pElement);

    	if(index!=-1)
    	{
    		returnAux=1;
    	}else
    	{
    		returnAux=0;
    	}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;

    void* pElement;
    int retorno;

    if(this!=NULL && this2 !=NULL)
    {
    	returnAux=1;

    	for(i=0;i<ll_len(this2);i++)
    	{
    		pElement=ll_get(this2, i);

    		retorno=ll_contains(this, pElement);

    		if(retorno==0)
    		{
    			returnAux=0;
    			break;
    		}


    	}


    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElement;
    int i;
    int tam=ll_len(this);


    if(this!=NULL && from>-1 && to<tam+1 && from<=to)
    {
    	cloneArray=ll_newLinkedList();

    	if(cloneArray!=NULL)
    	{
    		for(i=from;i<to;i++)
			{
				pElement= ll_get(this,i);
				ll_add(cloneArray, pElement);
			}
    	}

    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int tam=ll_len(this);

    if(this!=NULL)
    {
    	cloneArray=ll_subList(this, 0, tam);
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* pElementUno=NULL;
    void* pElementDos=NULL;
    void* auxElement=NULL;
    int banderaSwap;
    int tam;
    int i;
    int j;



    if(this!=NULL && pFunc!=NULL && (order==0 || order==1))
    {
    	tam=ll_len(this);
    	for(i=0;i<tam-1;i++)
    	{
    		pElementUno=ll_get(this, i);

    		for(j=i+1;j<tam;j++)
			{
				pElementDos=ll_get(this, j);
				banderaSwap=pFunc(pElementUno,pElementDos);

				if(order==0)
				{
					if(banderaSwap==-1)
					{
						auxElement=pElementUno;
						pElementUno=pElementDos;
						pElementDos=auxElement;
					}

				}else
				{
					if(banderaSwap==1)
					{
						auxElement=pElementDos;
						pElementDos=pElementUno;
						pElementUno=auxElement;

					}
				}

				ll_set(this, i, pElementUno);
				ll_set(this, j, pElementDos);
			}


    	}

    	returnAux=0;

    }
    return returnAux;

}

LinkedList* ll_filtro(LinkedList* this, int (*pFunc)(void*))
{
	LinkedList* nuevaLinkedList;
	void* pElement;

	if(this!=NULL && pFunc!=NULL)
	{
		int tam= ll_len(this);

		nuevaLinkedList=ll_newLinkedList();

		if(nuevaLinkedList!=NULL)
		{
			for(int i=0;i<tam;i++)
			{
				pElement=ll_get(this, i);


				if(pFunc(pElement)==0)// tambien se puede hacer asi: !pFunc(pElement)
				{
					ll_add(nuevaLinkedList, pElement);
				}
			}
		}


	}

	return nuevaLinkedList;

}

