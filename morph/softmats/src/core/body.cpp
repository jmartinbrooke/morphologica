#include "body.h"
#include "shapeconstr.h"

using namespace morph::softmats;

Body::Body(){
    
}

void Body::addShapeConstraint( Constraint *c ){
    if( c != NULL ){
        ((ShapeMatchingContraint *)c)->init( this );
        constraints.push_back( c );
    }
}

std::vector<Constraint *> Body::getConstraints(){
    return constraints;
}

TriangleMesh* Body::getMesh(){
    return this->mesh;
}

void Body::setMesh( TriangleMesh *mesh ){
    this->mesh = mesh;
}

Body::~Body(){
    delete mesh;
    
    for( Constraint *c : constraints )
        delete c;
}